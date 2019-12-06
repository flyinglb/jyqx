// uptime.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// Modified by Eatdami@MX (10/06/2000)

#include <mudlib.h>
#include <localtime.h>

inherit F_CLEAN_UP;
#define C(x) CHINESE_D->chinese_number(x)

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
	int t, d, h, m, s;
        string time,str;
        mixed* local;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        write(RED+CHINESE_MUD_NAME + " 已经执行了" +YEL+ time + RED"。\n"NOR);

        time = read_file(REBOOTFILE);
        if( sscanf(time,"%s:%d",str,t) == 2 ) {
                local = localtime(t);
                write(RED+CHINESE_MUD_NAME + " 由 " +YEL+ str + RED + "在" + YEL +
                        sprintf("%s月%s日%s时%s分",C(local[LT_MON]+1),C(local[LT_MDAY]),
                        C(local[LT_HOUR]),C(local[LT_MIN]+1)) + RED"重新启动。\n"NOR);
        }

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : uptime
 
这个指令告诉您「新金庸群侠传II」游戏已经连续执行了多久。
 
HELP
    );
    return 1;
}
