//Room: /d/dali/chahuashan3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨ɽ");
	set("long",@LONG
�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ����
���Ƿ�Ʒ����ż��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���
�ǵı��š���һЩ�����ڷ�����ȥ���ƺ����䳲(fengchao)����
�����軨���
LONG);
	set("objects", ([
	   __DIR__"npc/bee": 3,
	]));
	set("item_desc", ([
	   "fengchao" : "����һ��Ұ����ķ䳲��\n",
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"     : __DIR__"chahuashan2",
	]));
	setup();
	replace_program(ROOM);
}

