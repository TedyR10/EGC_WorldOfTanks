#version 330

// Input
in vec3 world_position;
in vec3 world_normal;

// Uniforms for light properties
uniform vec3 light_direction1;
uniform vec3 light_position1;
uniform vec3 light_direction2;
uniform vec3 light_position2;
uniform vec3 eye_position;

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

// TODO(student): Declare any other uniforms
uniform int spotLight;
uniform float cut_off_angle;
uniform int light;

uniform vec3 object_color;

// Output
layout(location = 0) out vec4 out_color;


void main()
{
    vec3 N = normalize(world_normal);
    vec3 L = normalize(light_position1 - world_position);
    vec3 L2 = normalize(light_position2 - world_position);
    vec3 R = normalize(reflect(L, world_normal));
    vec3 R2 = normalize(reflect(L2, world_normal));
    vec3 V = normalize(eye_position - world_position);
    vec3 H = normalize(L + V);
    vec3 H2 = normalize(L2 + V);

    // TODO(student): Define ambient, diffuse and specular light components
    float ambient_light = 0.25;
    float diffuse_light = material_kd * max(dot(N, L), 0);
    float diffuse_light2 = material_kd * max(dot(N, L2), 0);
    float specular_light1 = 0;
    float specular_light2 = 0;

    // It's important to distinguish between "reflection model" and
    // "shading method". In this shader, we are experimenting with the Phong
    // (1975) and Blinn-Phong (1977) reflection models, and we are using the
    // Phong (1975) shading method. Don't mix them up!

    if (diffuse_light > 0)
    {
        specular_light1 = material_ks * pow(max(dot(N, H), 0), material_shininess);
    }

    if (diffuse_light2 > 0)
    {
        specular_light2 = material_ks * pow(max(dot(N, H2), 0), material_shininess);
    }

    float intensity1 = 0;
    float intensity2 = 0;

    // TODO(student): If (and only if) the light is a spotlight, we need to do
    // some additional things.
    if (spotLight == 0) {
        float d1 = distance(light_position1, world_position);
        float attenuation_factor1 = 1.f / max(d1 * d1, 1.f);
        intensity1 = ambient_light + attenuation_factor1 * (diffuse_light + specular_light1);
    } else {
        float cut_off = radians(cut_off_angle);
        float spot_light = dot(-L, light_direction1);

        if (spot_light > cos(cut_off)) {
            // Quadratic attenuation
            float linear_att = (spot_light - cos(cut_off)) / (1.0f - cos(cut_off));
            float light_att_factor = linear_att * linear_att; // pow(linear_att, 2);

            intensity1 = ambient_light + light_att_factor * (diffuse_light + specular_light1);
        } else {
            intensity1 = ambient_light;
        }
    }

    
    float d2 = distance(light_position2, world_position);
    float attenuation_factor2 = 1.f / max(d2 * d2, 1.f);
    intensity2 = ambient_light + attenuation_factor2 * (diffuse_light2 + specular_light2);

    float intensity = intensity1 + intensity2;

    // TODO(student): Compute the total light. You can just add the components
    // together, but if you're feeling extra fancy, you can add individual
    // colors to the light components. To do that, pick some vec3 colors that
    // you like, and multiply them with the respective light components.

    // TODO(student): Write pixel out color
    vec3 col = object_color * intensity;
	out_color = vec4(col, 1.f);

}