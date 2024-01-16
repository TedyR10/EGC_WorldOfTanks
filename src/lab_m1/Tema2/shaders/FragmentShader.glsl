#version 330
// Copyright Theodor-Ioan Rolea 333CA 2023

uniform vec3 object_color;
uniform int health;

// Output
layout(location = 0) out vec4 out_color;

void main()
{
    float darkness = 0.25 + 0.75 * float(health) / 4.0;

    if (health == -1) {
        darkness = 0.25;
	}

    vec3 col = object_color * darkness;

    out_color = vec4(col, 1.0);
}