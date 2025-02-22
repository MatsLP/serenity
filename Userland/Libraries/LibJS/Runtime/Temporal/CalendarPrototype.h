/*
 * Copyright (c) 2021, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/Object.h>

namespace JS::Temporal {

class CalendarPrototype final : public Object {
    JS_OBJECT(CalendarPrototype, Object);

public:
    explicit CalendarPrototype(GlobalObject&);
    virtual void initialize(GlobalObject&) override;
    virtual ~CalendarPrototype() override = default;

private:
    JS_DECLARE_NATIVE_FUNCTION(id_getter);
    JS_DECLARE_NATIVE_FUNCTION(date_from_fields);
    JS_DECLARE_NATIVE_FUNCTION(year_month_from_fields);
    JS_DECLARE_NATIVE_FUNCTION(month_day_from_fields);
    JS_DECLARE_NATIVE_FUNCTION(year);
    JS_DECLARE_NATIVE_FUNCTION(month);
    JS_DECLARE_NATIVE_FUNCTION(month_code);
    JS_DECLARE_NATIVE_FUNCTION(day);
    JS_DECLARE_NATIVE_FUNCTION(day_of_week);
    JS_DECLARE_NATIVE_FUNCTION(day_of_year);
    JS_DECLARE_NATIVE_FUNCTION(week_of_year);
    JS_DECLARE_NATIVE_FUNCTION(days_in_week);
    JS_DECLARE_NATIVE_FUNCTION(days_in_month);
    JS_DECLARE_NATIVE_FUNCTION(days_in_year);
    JS_DECLARE_NATIVE_FUNCTION(months_in_year);
    JS_DECLARE_NATIVE_FUNCTION(in_leap_year);
    JS_DECLARE_NATIVE_FUNCTION(fields);
    JS_DECLARE_NATIVE_FUNCTION(merge_fields);
    JS_DECLARE_NATIVE_FUNCTION(to_string);
    JS_DECLARE_NATIVE_FUNCTION(to_json);
};

}
