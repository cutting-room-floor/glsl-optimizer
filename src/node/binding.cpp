#include <node.h>
#include <nan.h>
#include "shader.h"
#include <glsl_optimizer.h>

using namespace v8;

void InitAll(Handle<Object> exports)
{
	// Export constants
	exports->Set(NanNew<String>("VERTEX_SHADER"), NanNew<Number>(kGlslOptShaderVertex));
	exports->Set(NanNew<String>("FRAGMENT_SHADER"), NanNew<Number>(kGlslOptShaderFragment));
	exports->Set(NanNew<String>("TARGET_OPENGL"), NanNew<Number>(kGlslTargetOpenGL));
	exports->Set(NanNew<String>("TARGET_OPENGLES20"), NanNew<Number>(kGlslTargetOpenGLES20));
	exports->Set(NanNew<String>("TARGET_OPENGLES30"), NanNew<Number>(kGlslTargetOpenGLES30));
	
	// Export classes
	Compiler::Init(exports);
	Shader::Init(exports);
}

NODE_MODULE(glslOptimizer, InitAll);
