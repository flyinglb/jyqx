//Room: /d/dali/chahua1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰��");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨
԰�ڣ�������԰��ɫ��������ϲ���������߾ͽ�԰�ˣ�������һ����
�����ϱ���һ���᷿��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"bingqiku",
	    "south"  : __DIR__"xiuxishi",
	    "east"   : __DIR__"chahua2",
	    "west"   : __DIR__"tingyuan",
            "northwest"   : __DIR__"liangongfang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

