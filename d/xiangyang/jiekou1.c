// Room: /d/xiangyang/jiekou1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ֿ�");
	set("long", @LONG
��Ϊ�����ʮ�ֽֿڣ����Էǳ����֡�С��С����������
��ߺ���ţ��������ǵ���Ʒ����Ȼ���������ɹž����ţ�����
��������������˿���Ľ��ţ�����������˾�ռ��ߡ�ϰ��Ϊ��
�ˡ�����������Ǻ�ͬ����������ǵ��ϰ���ס�����棬����
����������ʯ�̾͵Ĵ�֡�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"northroad1",
		"south" : __DIR__"westroad2",
		"west"  : __DIR__"hutong1",
		"north" : __DIR__"hutong2",
	]));
	set("objects", ([
		"/d/village/npc/seller" : 1,
	]));
	setup();
	replace_program(ROOM);
}

