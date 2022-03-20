#pragma execution_character_set("utf-8")
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <Windows.h>

using namespace std;
namespace py = pybind11;
using namespace py::literals;


class UmamusumeTextHashCalc {
    public:
        UmamusumeTextHashCalc(){
        }

        wchar_t* utf8togbk(const char* strUTF8) {
            int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
            wchar_t* wszGBK = new wchar_t[len + 1];
            memset(wszGBK, 0, len * 2 + 2);
            MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
            len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
            char* szGBK = new char[len + 1];
            memset(szGBK, 0, len + 1);
            return wszGBK;

            /*
            WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
            std::string strTemp(szGBK);
            if (wszGBK) delete[] wszGBK;
            if (szGBK) delete[] szGBK;
            return strTemp;
            */
        }

        size_t calc(char* textinput) {
            /*
            string nb = utf8togbk(textinput);
            size_t len = strlen(nb.c_str()) + 1;
            size_t converted = 0;
            wchar_t* WStr;
            WStr = (wchar_t*)malloc(len * sizeof(wchar_t));

            mbstowcs_s(&converted, WStr, len, nb.c_str(), _TRUNCATE);
            */

            auto test1 = std::hash<wstring>{}(utf8togbk(textinput));
            // auto test2 = std::hash<wstring>{}(L"わわわっ、wuhud♪(^_-)！！");
            // printf("haha: %zu\n", test2);
            return test1;
        }

        // std::string textinput;

};

PYBIND11_MODULE(cppy_gb, m) {
    m.doc() = "umamusume textid calculator";

    py::class_<UmamusumeTextHashCalc>(m, "UmamusumeTextHashCalc")
        .def(py::init<>())
        .def("calc", &UmamusumeTextHashCalc::calc)
        ;
}

