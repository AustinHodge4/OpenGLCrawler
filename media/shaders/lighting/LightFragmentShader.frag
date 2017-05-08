// shadertype=glsl
#version 330 core
out vec4 color;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

struct Material {
	vec3 ambient;
	vec3 diffuse;
	sampler2D diffuseTexture;
	vec3 specular;
	sampler2D specularTexture;
	float shininess;
};
struct DirLight {
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
struct PointLight {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};
struct SpotLight {
    vec3 position;
	vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

	float constant;
	float linear;
	float quadratic;

	float cutOff;
	float outterCutOff;
};

uniform vec3 viewPos;

uniform Material material;

uniform DirLight dirLight;

#define NR_POINT_LIGHTS 4
uniform PointLight pointLights[NR_POINT_LIGHTS];

uniform SpotLight spotLight;

uniform bool useTexture;

vec3 CalculateDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalculatePointLights(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
	vec3 norm = normalize(Normal);
	vec3 viewDir = normalize(viewPos - FragPos);

	vec3 result = CalculateDirLight(dirLight, norm, viewDir);

	for(int i = 0; i < NR_POINT_LIGHTS; i++)
		result += CalculatePointLights(pointLights[i], norm, FragPos, viewDir);

	result += CalculateSpotLight(spotLight, norm, FragPos, viewDir);

	vec4 tex = texture(material.diffuseTexture, TexCoords);
	color = vec4(result, useTexture ? tex.a : 1.0f);
}
vec3 CalculateDirLight(DirLight light, vec3 normal, vec3 viewDir){

    vec3 ambient = (useTexture ? vec3(texture(material.diffuseTexture, TexCoords)) : material.ambient) * light.ambient;

	vec3 lightDir = normalize(-light.direction);
	float dif = max(dot(lightDir, normal), 0.0f);
	vec3 diffuse = (dif * (useTexture ? vec3(texture(material.diffuseTexture, TexCoords)) : material.diffuse)) * light.diffuse;
	
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = (spec * (useTexture ? vec3(texture(material.specularTexture, TexCoords)) : material.specular)) * light.specular;
	  
	return (ambient + diffuse + specular);
}
vec3 CalculatePointLights(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir){

    vec3 ambient = (useTexture ? vec3(texture(material.diffuseTexture, TexCoords)) : material.ambient) * light.ambient;
	
	vec3 lightDir = normalize(light.position - fragPos);
	float dif = max(dot(normal, lightDir), 0.0f);
	vec3 diffuse = (dif * (useTexture ? vec3(texture(material.diffuseTexture, TexCoords)) : material.diffuse)) * light.diffuse;

	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = (spec * (useTexture ? vec3(texture(material.specularTexture, TexCoords)) : material.specular)) * light.specular;
	
	float distance = length(light.position - FragPos);
	float attenuation = 1.0f/(light.constant + (light.linear * distance) + (light.quadratic * (distance * distance)));

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return (ambient + diffuse + specular);
}
vec3 CalculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir){

    vec3 ambient = (useTexture ? vec3(texture(material.diffuseTexture, TexCoords)) : material.ambient) * light.ambient;

	vec3 lightDir = normalize(light.position - fragPos);

	float angle = dot(lightDir, normalize(-light.direction));
	float epsilon   = light.cutOff - light.outterCutOff;
	float intensity = clamp((angle - light.outterCutOff) / epsilon, 0.0, 1.0);   

	float distance = length(light.position - fragPos);
	float attenuation = 1.0f/(light.constant + (light.linear * distance) + (light.quadratic * (distance * distance)));
	  
	float dif = max(dot(normal, lightDir), 0.0f);
	vec3 diffuse = (dif * (useTexture ? vec3(texture(material.diffuseTexture, TexCoords)) : material.diffuse)) * light.diffuse;

	vec3 reflectDir = reflect(-lightDir, normal); 
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = (spec * (useTexture ? vec3(texture(material.specularTexture, TexCoords)) : material.specular)) * light.specular;  
			
	ambient *= attenuation * intensity;
	diffuse *= attenuation * intensity;
	specular *= attenuation * intensity;

	return (diffuse + ambient + specular);
}
