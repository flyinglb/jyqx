/* 
 * ftime.c
 * format times
 * Make By Luky@Hero
 * modify byp@jyqxz 2000/09/16
 *
 * example : parse string link "Sun May  3 00:52:12 1998"
 *
 * type  1 : 1998 May 3 00:52:12 Sun
 * type  2 : May 3 00:52:12 1998 Sun
 * type  3 : 1998 May 3 00:52:12
 * type  4 : May 3 00:52:12 Sun
 * type  5 : May 3 00:52:12 1998
 * type  6 : May 3 00:52:12
 * type  7 : 3 00:52:12 Sun
 * type  8 : 3 00:52:12
 * type  9 : 1998 May 3 00:52:12 Sun
 * type 10 : 1998 May 3 00:52:12 Sun
 * type 11 : 1998 May 3 00:52:12 Sun
 * type 12 : 一九九八年十月三十一日三点二十分 星期六
 * type 13 : 一九九八年十月三十一日三点二十分
 * type 14 : 十月三十一日三点二十分 星期六
 * type 15 : 十月三十一日三点二十分
 * type 16 : 1998年10月31日3点20分 星期六
 * type 17 : 1998年10月31日3点20分
 * type 18 : 10月31日3点20分
 * type 19 : 00:52:12
 *
 */
 
string ftime(int type, string times)
{
        string e_time, e_year, e_month, e_week;//english
        string c_time, c_year, c_month, c_week;//chinese
        string c_day, c_hour, c_minute, c_second;//chinese
        int day, hour, minute, second, time;
        
        string *month_filter = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});
        string *week_filter = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});
        
        if( (time = atoi(times)) == 0 )
                e_time = ctime(time());
        else e_time = ctime(time);
        
        sscanf(e_time,"%s %s %d %d:%d:%d %s", e_week, e_month, day, hour, minute, second, e_year);
        
        c_week  = chinese_number(member_array(e_week, week_filter) + 1);
        c_month = chinese_number(member_array(e_month, month_filter) + 1);
        c_year  = sprintf("%s%s%s%s",chinese_number(e_year[0]-48),chinese_number(e_year[1]-48),
                                     chinese_number(e_year[2]-48),chinese_number(e_year[3]-48));

        c_year = c_year + "年";
        c_month  = c_month + "月";
        c_week = " 星期"+ c_week;
        c_day = chinese_number(day) + "日";
        c_hour = chinese_number(hour) + "点";
        c_minute = chinese_number(minute) + "分";
        c_second = chinese_number(second) + " 秒";
        
        if (type) {
                switch( type ) {//欢迎加入更多的类型
                        case  1: return e_year+" "+e_month+" "+day+" "+hour+":"+minute+":"+second+" "+e_week;
                        case  2: return e_month+" "+day+" "+hour+":"+minute+":"+second+" "+e_year+" "+e_week;
                        case  3: return e_year+" "+e_month+" "+day+" "+hour+":"+minute+":"+second;
                        case  4: return e_month+" "+day+" "+hour+":"+minute+":"+second+" "+e_week;
                        case  5: return e_month+" "+day+" "+hour+":"+minute+":"+second+" "+e_year;
                        case  6: return e_month+" "+day+" "+hour+":"+minute+":"+second;
                        case  7: return day+" "+hour+":"+minute+":"+second+" "+e_week;
                        case  8: return day+" "+hour+":"+minute+":"+second;
                        case  9: return hour+":"+minute+":"+second;
                        case 10: return c_year+c_month+c_day+c_hour+c_minute+c_second+c_week;//chinese
                        case 11: return c_year+c_month+c_day+c_hour+c_minute+c_second;
                        case 12: return c_year+c_month+c_day+c_hour+c_minute;
                        case 13: return c_month+c_day+c_hour+c_minute+c_week;
                        case 14: return c_month+c_day+c_hour+c_minute;
                        case 15: return c_day+c_hour+c_minute+c_second;
                        case 16: return c_hour+c_minute+c_second;
                        case 17: return e_year+"年"+(member_array(e_month, month_filter) + 1)+
                                "月"+day+"日"+hour+"点"+minute+"分"+c_week;
                        case 18: return e_year+"年"+(member_array(e_month, month_filter) + 1)+
                                "月"+day+"日"+hour+"点"+minute+"分";
                        case 19: return (member_array(e_month, month_filter) + 1)+
                                "月"+day+"日"+hour+"点"+minute+"分";
                        default: return e_month+" "+day+" "+hour+":"+minute+":"+second+" "+e_year;
                }
        } 
        return e_year+" "+e_month+" "+day+" "+hour+":"+minute+":"+second+" "+e_week;
}
