static PyMethodDef methods_[] = {
    {NULL, NULL}
};

static ConstDef consts_[] = {
    {"SEETA_DEVICE_AUTO", SEETA_DEVICE_AUTO},
    {"SEETA_DEVICE_CPU", SEETA_DEVICE_CPU},
    {"SEETA_DEVICE_GPU", SEETA_DEVICE_GPU},
    {NULL, 0}
};

static PyMethodDef methods_bv[] = {
    {"save", (PyCFunction)pybv_bv_save, METH_VARARGS | METH_KEYWORDS, "save(mat) -> None\n."},
    {NULL, NULL}
};

static ConstDef consts_bv[] = {
    {NULL, 0}
};

static PyMethodDef methods_seeta[] = {
    {NULL, NULL}
};

static ConstDef consts_seeta[] = {
    {"ModelBuffer_AUTO", seeta::ModelBuffer::AUTO},
    {"MODEL_BUFFER_AUTO", seeta::ModelBuffer::AUTO},
    {"ModelBuffer_CPU", seeta::ModelBuffer::CPU},
    {"MODEL_BUFFER_CPU", seeta::ModelBuffer::CPU},
    {"ModelBuffer_GPU", seeta::ModelBuffer::GPU},
    {"MODEL_BUFFER_GPU", seeta::ModelBuffer::GPU},
    {"ModelSetting_AUTO", seeta::ModelSetting::AUTO},
    {"MODEL_SETTING_AUTO", seeta::ModelSetting::AUTO},
    {"ModelSetting_CPU", seeta::ModelSetting::CPU},
    {"MODEL_SETTING_CPU", seeta::ModelSetting::CPU},
    {"ModelSetting_GPU", seeta::ModelSetting::GPU},
    {"MODEL_SETTING_GPU", seeta::ModelSetting::GPU},
    {NULL, 0}
};

static PyMethodDef methods_seeta_v6[] = {
    {NULL, NULL}
};

static ConstDef consts_seeta_v6[] = {
    {"FaceAntiSpoofing_DETECTING", seeta::v6::FaceAntiSpoofing::DETECTING},
    {"FACE_ANTI_SPOOFING_DETECTING", seeta::v6::FaceAntiSpoofing::DETECTING},
    {"FaceAntiSpoofing_FUZZY", seeta::v6::FaceAntiSpoofing::FUZZY},
    {"FACE_ANTI_SPOOFING_FUZZY", seeta::v6::FaceAntiSpoofing::FUZZY},
    {"FaceAntiSpoofing_PROPERTY_ARM_CPU_MODE", seeta::v6::FaceAntiSpoofing::PROPERTY_ARM_CPU_MODE},
    {"FACE_ANTI_SPOOFING_PROPERTY_ARM_CPU_MODE", seeta::v6::FaceAntiSpoofing::PROPERTY_ARM_CPU_MODE},
    {"FaceAntiSpoofing_PROPERTY_NUMBER_THREADS", seeta::v6::FaceAntiSpoofing::PROPERTY_NUMBER_THREADS},
    {"FACE_ANTI_SPOOFING_PROPERTY_NUMBER_THREADS", seeta::v6::FaceAntiSpoofing::PROPERTY_NUMBER_THREADS},
    {"FaceAntiSpoofing_REAL", seeta::v6::FaceAntiSpoofing::REAL},
    {"FACE_ANTI_SPOOFING_REAL", seeta::v6::FaceAntiSpoofing::REAL},
    {"FaceAntiSpoofing_SPOOF", seeta::v6::FaceAntiSpoofing::SPOOF},
    {"FACE_ANTI_SPOOFING_SPOOF", seeta::v6::FaceAntiSpoofing::SPOOF},
    {NULL, 0}
};

static void init_submodules(PyObject * root) 
{
  init_submodule(root, MODULESTR"", methods_, consts_);
  init_submodule(root, MODULESTR"", methods_bv, consts_bv);
  init_submodule(root, MODULESTR"eta", methods_seeta, consts_seeta);
  init_submodule(root, MODULESTR"eta.v6", methods_seeta_v6, consts_seeta_v6);
};
