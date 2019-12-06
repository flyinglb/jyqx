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

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        write(RED+CHINESE_MUD_NAME + " �Ѿ�ִ����" +YEL+ time + RED"��\n"NOR);

        time = read_file(REBOOTFILE);
        if( sscanf(time,"%s:%d",str,t) == 2 ) {
                local = localtime(t);
                write(RED+CHINESE_MUD_NAME + " �� " +YEL+ str + RED + "��" + YEL +
                        sprintf("%s��%s��%sʱ%s��",C(local[LT_MON]+1),C(local[LT_MDAY]),
                        C(local[LT_HOUR]),C(local[LT_MIN]+1)) + RED"����������\n"NOR);
        }

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : uptime
 
���ָ����������½�ӹȺ����II����Ϸ�Ѿ�����ִ���˶�á�
 
HELP
    );
    return 1;
}
