// Room: /guiyun/dating.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǹ���ׯ�������������޽������Զ������������Ϊ�¾ɣ�
����ɨ��ʮ�ָɾ�������Ҳ��Ϊ���㣬��ȫû�г����լ������֮
�����ıڹ���һЩ�����黭��Ʒ����Ϊ�ϳ�֮�����Ե������۹ⲻ
�������д������֡�
LONG );
//      set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"qianyuan",
		"east"  : __DIR__"shufang",
	]));
	set("objects", ([
		__DIR__"npc/kezhene" : 1,
		__DIR__"npc/zhucong" : 1,
		__DIR__"npc/hanbaoju" : 1,
		__DIR__"npc/nanxiren" : 1,
		__DIR__"npc/zhangasheng" : 1,
		__DIR__"npc/quanjinfa" : 1,
		__DIR__"npc/hanxiaoyin" : 1,
	]));
	setup();
	replace_program(ROOM);
}
