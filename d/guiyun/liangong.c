// Room: /guiyun/liangong.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǹ���ׯ½��ׯ����������������½��ׯ����������֧��
ϼ�ɳ������Է��в��þ���Ϊϰ������Ӳ��֮�ã������Ų���ľ
׮�ͲݰС����߽��ϻ���������ɳ�ӣ��컨���ϵ���һ֧��ɳ����
LONG );
//	set("no_clean_up", 0);

	set("exits", ([
		"west"  : __DIR__"huayuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 3,
	]));
	setup();
	replace_program(ROOM);
}
