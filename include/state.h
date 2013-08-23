#pragma once

#include <elements.h>
#include <glm/glm.hpp>

class Camera;
class GLProgram;
class GLUniformBuffer;
class GLUniformBuffer;

class State {
public:
  State();
  ~State();

  GLProgram * program;
  GLUniformBuffer * material;
  glm::mat4 transform;
  GLUniformBuffer * glcamera;
  CacheElement cacheelem;
  VertexElement vertexelem;

private:
  void push();
  void pop();
  friend class StateScope;

  class StateP;
  std::unique_ptr<StateP> self;
};

class StateScope {
public:
  StateScope(State * state) : state(state) { state->push(); }
  ~StateScope() { state->pop(); }
private:
  State * state;
};