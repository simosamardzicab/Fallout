#include "wxWidgetsUserData.h"
#include "ntst_loggingpp.hpp"
#include "Common.h"
#include <cstdint>

void SetWidgetLbTxtPairData(wxListBox *lb, wxTextCtrl *txt, PairTxtLb *p)
    {
    lb->SetClientData(p);
    txt->SetClientData(p);
    }

void SetWidgetData(wxWindow *widget, size_t offset)
    {
    widget->SetClientData(reinterpret_cast<void*>(offset));
    }

size_t GetWidgetData(wxWindow *widget)
    {
    return reinterpret_cast<size_t>(widget->GetClientData());
    }

void SetWidgetData(wxWindow *widget, unsigned function, size_t offset)
    {
    widget->SetClientData(reinterpret_cast<void*>(function + offset * 32));
    }

void GetWidgetData(wxWindow *widget, unsigned *function, size_t *offset)
    {
    uintptr_t data = reinterpret_cast<uintptr_t>(widget->GetClientData());
    *function = data % 32;
    *offset = data / 32;
    if (*function == 0 && *offset == 0)
        ntst_log_warning("Function and offset are not set for widget: " + WxStringToStdUTF8(widget->GetName()));
    }
