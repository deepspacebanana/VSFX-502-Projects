/* 
 CutrPaperCup.cpp
 Generated by Cutter from:
     "/Users/malcolm/Documents/maya/projects/RMS_ris/Args/CutrPaperCup.args"
 at 8.15:49am 1.31.2015
*/
#include <RixPattern.h> 
#include <RixShadingUtils.h>
#include <RixShading.h>
#include <cstring>
//#include <cstdio>
//#include <sstream>
//#include <math.h>

class CutrPaperCup : public RixPattern {
public:

    CutrPaperCup();
    virtual ~CutrPaperCup() { }
    virtual int Init(RixContext &, char const *pluginpath);
    virtual RixSCParamInfo const *GetParamTable();
    virtual void Finalize(RixContext &) { }
    virtual int ComputeOutputParams(RixShadingContext const *ctx,
                                    RtInt *noutputs, 
                                    OutputSpec **outputs,
                                    RtConstPointer instanceData,
                                    RixSCParamInfo const *ignored);
	private:
		RixMessages *m_msg;
		RtFloat		m_cup_height;
		RtInt		m_freq;
		RtFloat		m_atten_upper;
		RtFloat		m_atten_lower;
		RtInt		m_atten_ridges;
		RtFloat		m_ridge_sharpness;
		RtFloat		m_ridge_distort;
		RtFloat		m_ridge_distort_scale;
		RtFloat		m_mask_amp;
		RtFloat		m_mask_offset;
		RtInt		m_mask_invert;
		RtFloat		m_mask_gain;

	};

CutrPaperCup::CutrPaperCup():
	m_msg(NULL),  
	m_cup_height(1.5),
	m_freq(30),
	m_atten_upper(0.2),
	m_atten_lower(0.05),
	m_atten_ridges(0),
	m_ridge_sharpness(0),
	m_ridge_distort(0),
	m_ridge_distort_scale(0),
	m_mask_amp(0.25),
	m_mask_offset(0.75),
	m_mask_invert(0),
	m_mask_gain(1.0)
	{ }
int CutrPaperCup::Init(RixContext &ctx, char const *pluginpath) {
    m_msg = (RixMessages*)ctx.GetRixInterface(k_RixMessages);
    // Uncomment the next three lines if a rib Option will be queried.
    //RixRenderState *rstate = (RixRenderState*)ctx.GetRixInterface(k_RixRenderState);
    //RixRenderState::Type optType;
    //RtInt optNumValues, err;

    return (!m_msg) ? 1 : 0;
    }

RixSCParamInfo const *CutrPaperCup::GetParamTable() {
    static RixSCParamInfo s_ptable[] = {
		// Outputs
		RixSCParamInfo("ridgesF", k_RixSCFloat, k_RixSCOutput),
		RixSCParamInfo("maskF", k_RixSCFloat, k_RixSCOutput),
		// Inputs
		RixSCParamInfo("cup_height", k_RixSCFloat),
		RixSCParamInfo("freq", k_RixSCInteger),
		RixSCParamInfo("atten_upper", k_RixSCFloat),
		RixSCParamInfo("atten_lower", k_RixSCFloat),
		RixSCParamInfo("atten_ridges", k_RixSCInteger),
		RixSCParamInfo("ridge_sharpness", k_RixSCFloat),
		RixSCParamInfo("ridge_distort", k_RixSCFloat),
		RixSCParamInfo("ridge_distort_scale", k_RixSCFloat),
		RixSCParamInfo("mask_amp", k_RixSCFloat),
		RixSCParamInfo("mask_offset", k_RixSCFloat),
		RixSCParamInfo("mask_invert", k_RixSCInteger),
		RixSCParamInfo("mask_gain", k_RixSCFloat),
		RixSCParamInfo() // end of table
        };
    return &s_ptable[0];
    }

enum paramIndex {
	k_ridgesF = 0,
	k_maskF,
	k_cup_height,
	k_freq,
	k_atten_upper,
	k_atten_lower,
	k_atten_ridges,
	k_ridge_sharpness,
	k_ridge_distort,
	k_ridge_distort_scale,
	k_mask_amp,
	k_mask_offset,
	k_mask_invert,
	k_mask_gain
    };
	
int CutrPaperCup::ComputeOutputParams(RixShadingContext const *ctx,
								RtInt *noutputs, 
								OutputSpec **outputs,
								RtConstPointer instanceData,
								RixSCParamInfo const *ignored) {

    // Uncomment the next three lines if a rib Attribute will be queried. Note
    // that Rib Options should be queried in the init() method - not here!
    //RixRenderState *rstate = (RixRenderState*)ctx->GetRixInterface(k_RixRenderState);
    //RixRenderState::Type attrType;
    //RtInt attrNumValues, err;

    bool varying = true;
    bool uniform = false;

    // Declare a pointer for each input then obtain their values
    // using EvalParam().
	RtFloat		const *cup_height;
	RtInt		const *freq;
	RtFloat		const *atten_upper;
	RtFloat		const *atten_lower;
	RtInt		const *atten_ridgesPtr;
	RtFloat		const *ridge_sharpness;
	RtFloat		const *ridge_distort;
	RtFloat		const *ridge_distort_scale;
	RtFloat		const *mask_amp;
	RtFloat		const *mask_offset;
	RtInt		const *mask_invertPtr;
	RtFloat		const *mask_gain;

	ctx->EvalParam(k_cup_height, -1,  &cup_height, &m_cup_height, varying);
	ctx->EvalParam(k_freq, -1, &freq, &m_freq, varying);
	ctx->EvalParam(k_atten_upper, -1, &atten_upper, &m_atten_upper, varying);
	ctx->EvalParam(k_atten_lower, -1, &atten_lower, &m_atten_lower, varying);
	ctx->EvalParam(k_atten_ridges, -1, &atten_ridgesPtr, &m_atten_ridges, uniform);
	ctx->EvalParam(k_ridge_sharpness, -1, &ridge_sharpness, &m_ridge_sharpness, varying);
	ctx->EvalParam(k_ridge_distort, -1, &ridge_distort, &m_ridge_distort, varying);
	ctx->EvalParam(k_ridge_distort_scale, -1, &ridge_distort_scale, &m_ridge_distort_scale, varying);
	ctx->EvalParam(k_mask_amp, -1, &mask_amp, &m_mask_amp, varying);
	ctx->EvalParam(k_mask_offset, -1, &mask_offset, &m_mask_offset, varying);
	ctx->EvalParam(k_mask_invert, -1, &mask_invertPtr, &m_mask_invert, uniform);
	ctx->EvalParam(k_mask_gain, -1, &mask_gain, &m_mask_gain, varying);

    // Allocate memory for the OutputSpec data structure.
    RixShadingContext::Allocator pool(ctx);
	OutputSpec *outSpec = pool.AllocForPattern<OutputSpec>(2);
	*outputs = outSpec;

    // Allocate memory for each output.
	RtFloat	*ridgesF = pool.AllocForPattern<RtFloat>(ctx->numPts);
	RtFloat	*maskF = pool.AllocForPattern<RtFloat>(ctx->numPts);

    // Connect the output(s) to the OutputSpec.
    *noutputs = 2;
	outSpec[0].paramId = k_ridgesF;
	outSpec[0].detail = k_RixSCVarying;
	outSpec[0].value = ridgesF;
	outSpec[1].paramId = k_maskF;
	outSpec[1].detail = k_RixSCVarying;
	outSpec[1].value = maskF;

	// 1 Get a pointer to an array of surface positions.
	RtPoint3 const  *P;
	ctx->GetBuiltinVar(RixShadingContext::k_P, &P);
	
	// 2 Grab enough memory to store a copy the original P data.
	RtPoint3 *objP = pool.AllocForPattern<RtPoint3>(ctx->numPts);
	
	// 3 Copy the original P data to the objP array.
	memcpy(objP, P, sizeof(RtPoint3) * ctx->numPts);
	
	// 4 Transform will over-write the original objP data.
	ctx->Transform(RixShadingContext::k_AsPoints, "current", "object", objP, NULL);
	
	//_____________________________________________________
	float theta, ridges;
	float y, wave, h;
	float mask;	
	int	  attenRidges = *atten_ridgesPtr;
	int	  maskInvert = *mask_invertPtr;
	
    // Assign values to each point.
    for(int i = 0; i < ctx->numPts; i++) {
		theta = atan2(objP[i].x, objP[i].z) + ridge_distort[i] * ridge_distort_scale[i];
		ridges = sin(theta * freq[i]);
		
		// Make the sine wave more triangular by adding "odd" harmonics to the sine wave.
		for(int n = 1; n < ridge_sharpness[i] * 10; n++) {
            h = n * 2 + 1;
            wave = sin(theta * freq[n] * h)/pow(h, 2);
			ridges += (n % 2 == 0) ? wave : -wave;
            }
		// To compensate for any "sharpening" of the ridges a value slightly 
		// greater than 1.0 should be added.
		ridgesF[i] = ridges + 1.0;
		
		y = objP[i].y; 
		if(attenRidges > 0)
	        ridgesF[i] *= RixSmoothStep(atten_lower[i], atten_upper[i], y);

		// Remap the y position of the shading point to the range 0 to 1.
		y = y/cup_height[i];
		mask = (ridges + 2) * RixSmoothStep(mask_offset[i], mask_offset[i] + mask_amp[i], y);
		mask = RixSmoothStep(0.0, 0.85, mask);
		maskF[i] = (maskInvert) ? 1 - mask : mask;
        } 
    return 0;

    }

RIX_PATTERNCREATE {
    return new CutrPaperCup();
    }
RIX_PATTERNDESTROY {
    delete ((CutrPaperCup*)pattern);
    }