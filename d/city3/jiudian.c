// Room: jiudian.c
// Date: Feb..14.1998 by Java

inherit ROOM;
void create()
{
	set("short", "�񶼾�¥");
	set("long", @LONG
����һ����������������Ĵ��¥����˵���ϵ���������ȴҲ��
�ɲ��������������Ϲ���һ�������ң���д�š��񶼾�¥���ĸ�����
���֡�¥�������ξ������п������κ��ݣ�ʮ���Ǹ��̴�֡�����һ
�Ұ����ϵ꣬�������ڵ���λ�ƹ��Ѿ��ǵ��Ĵ�����˵���ᶽ������
�㲻�����ȴҲ����������¥���ս����𡣶��Ͻ���һ������ͨ��
¥������������������Գ�������֡�
LONG );
	set("exits", ([
		"southwest" : __DIR__"eastroad1",
	]));
        set("objects", ([
                __DIR__"npc/tanghua" : 1,
                __DIR__"npc/xiaoer2" : 1,
        ]) );
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
