#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "��");
        set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�
����ֻ�к��˵��Ĵ�����
LONG);   
	set("outdoors", "taohua");
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM) ;
}
