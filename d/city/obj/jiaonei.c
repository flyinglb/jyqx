
#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "����");
        set("long",@LONG
���ڽ�������ȣ����ҡ��ҡ��̧������ǰ���ˡ���ֻ���Ľ���
����ҡ��ҡ����Ҳ��֪�����˶�ã�һ·���Ͼ��û����˯......
LONG);   
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
