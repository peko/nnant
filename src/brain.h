#pragma once

brain_p brain_new();
brain_p brain_load(const char* filename);
void brain_save(const char* filename);
void brain_free(brain_p brain);
void brain_update(brain_p brain, float* vision, float** action);
void brain_mutate(brain_p brain);
