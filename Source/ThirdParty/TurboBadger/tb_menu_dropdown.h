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

#ifndef TB_MENU_DROPDOWN_H
#define TB_MENU_DROPDOWN_H

#include "tb_menu_window.h"

namespace tb {

class TBMenuDropdown : public TBButton, public TBSelectItemViewer
{
public:
    // For safe typecasting
    TBOBJECT_SUBCLASS(TBMenuDropdown, TBButton);

    TBMenuDropdown();
    ~TBMenuDropdown();

    TBGenericStringItemSource *GetDefaultSource() { return &m_default_source; }

    void OpenMenu();

    void CloseMenu();

    TBMenuWindow *GetMenuIfOpen() const;

    virtual void OnInflate(const INFLATE_INFO &info);
    virtual bool OnEvent(const TBWidgetEvent &ev);

    // == TBSelectItemViewer ==================================================
    virtual void OnSourceChanged() {}
    virtual void OnItemChanged(int index) {}
    virtual void OnItemAdded(int index) {}
    virtual void OnItemRemoved(int index) {}
    virtual void OnAllItemsRemoved() {}
private:    
    TBGenericStringItemSource m_default_source;
    TBWidgetSafePointer m_window_pointer; ///< Points to the dropdown window if opened
};

}; // namespace tb

#endif // TB_MENU_DROPDOWN_H
