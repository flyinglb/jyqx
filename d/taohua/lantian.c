#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "����");
        set("long",@LONG
�������������죬��׵�����Ʈ�����ϵ����˿����������ϡ���......
��ˬ������������һ�ָо�����������һ���˼�С��
LONG);   
	set("outdoors", "taohua");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
