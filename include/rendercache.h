#pragma once

#include <vector>
#include <memory>
#include <opengl.h>

class DrawCache {
public:
  DrawCache(GLProgram * program,
            GLUniformBuffer * material,
            GLUniformBuffer * glcamera,
            GLUniformBuffer * transform,
            GLVertexArrayObject * vao,
            GLDrawCall * drawcall);

  void flush(State * state);

  GLProgram * program;
  GLDrawCall * drawcall;
  GLUniformBuffer * material;
  GLUniformBuffer * glcamera;
  GLUniformBuffer * transform;
  GLVertexArrayObject * vao;
};

class RenderCache {
public:
  RenderCache();
  ~RenderCache();

  void compile();
  void flush(State * state);

  std::vector<DrawCache> drawlist;
  //std::vector<std::function<void()>> glcalls;
};