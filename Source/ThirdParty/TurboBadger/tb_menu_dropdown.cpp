//
// Copyright (c) 2014-2015, THUNDERBEAST GAMES LLC All rights reserved
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include "tb_menu_dropdown.h"
#include "tb_widgets_listener.h"

namespace tb {

// == TBMenuDropdown ==========================================

TBMenuDropdown::TBMenuDropdown()
{
    SetSource(&m_default_source);
    SetSkinBg(TBIDC("TBSelectDropdown"), WIDGET_INVOKE_INFO_NO_CALLBACKS);
}

TBMenuDropdown::~TBMenuDropdown()
{
    SetSource(nullptr);
    CloseMenu();
}

void TBMenuDropdown::OpenMenu()
{
    if (!m_source || !m_source->GetNumItems() || m_window_pointer.Get())
        return;

    if (TBMenuWindow *window = new TBMenuWindow(this, TBIDC("TBMenuWindow")))
    {
        m_window_pointer.Set(window);
        window->Show(m_source, TBPopupAlignment());
    }
}

void TBMenuDropdown::CloseMenu()
{
    if (TBMenuWindow *window = GetMenuIfOpen())
        window->Close();
}

TBMenuWindow *TBMenuDropdown::GetMenuIfOpen() const
{
    return TBSafeCast<TBMenuWindow>(m_window_pointer.Get());
}

bool TBMenuDropdown::OnEvent(const TBWidgetEvent &ev)
{
    if (ev.target == this && ev.type == EVENT_TYPE_CLICK && !GetMenuIfOpen())
    {
        OpenMenu();
        return true;
    }
    return false;
}

}; // namespace tb
