// Room: /guiyun/shufang.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����½ׯ�����鷿��������Ŀ��ȫ��ʫ��伮���������ϰ���
���ͭ���������������ǹ�����Ϲ���һ��ˮī���������Ǹ���
������������֮ҹ��ͥ�������ְ����������쳤���������į����
�Ͻ�����һ�ס��ʡ�(poem)�����������ббǶ��һ�������ԣ���
�����ͷ��䲻̫��ġ�
LONG );
//      set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"west"  : __DIR__"dating",
	]));
	set("item_desc", ([
		"poem"  :
"
��ҹ���˲�ס��������ǧ���Σ���������
���������ƽ��С������ģ�������������

����Ϊ��������ɽ�����ϣ����̡�
�������¸����٣�֪���٣��Ҷ���˭����

                ������˲���Ϳѻ
",
	]));
	set("objects", ([
		CLASS_D("taohua")+"/lu" : 1,
		__DIR__"npc/shutong" : 1,
	]));
	setup();
	replace_program(ROOM);
}
