//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ʥ��");
	set("long", @LONG
���ꡰ������ʥ��������ڴ�ȺɽΧ�Ƶ�ɽ���ﴴ������һ�ɣ��������
�˵����𽥽������ľ߹�ģ������Ժ�䣬�������еĴ���Ϊ�����俪����ʦ��
����Ϊ����ʥ�ӡ������������������������ɵ��Խ�������������ֱ�����
��������������
LONG );
	set("exits", ([
		"south"  : __DIR__"sansheng",
		"north"  : __DIR__"shijian",
		"west"  : __DIR__"yidao",
		"east" :  __DIR__"qinyu",
	]));
        set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/weisiniang" : 1,
	]));
	set("no_clean_up", 0);
	setup();
        "/clone/board/kunlun_b"->foo();
	replace_program(ROOM);
}

