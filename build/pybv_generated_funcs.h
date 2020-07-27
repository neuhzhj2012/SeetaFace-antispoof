static PyObject* pybv_bv_save(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace bv;

    {
    PyObject* pyobj_mat = NULL;
    Mat mat;

    const char* keywords[] = { "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:save", (char**)keywords, &pyobj_mat) &&
        pybv_to(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(bv::save(mat));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_mat = NULL;
    Mat mat;

    const char* keywords[] = { "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:save", (char**)keywords, &pyobj_mat) &&
        pybv_to(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(bv::save(mat));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}

