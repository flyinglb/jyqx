// Room: /guiyun/jinship.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "���ս��");
	set("long", @LONG
�����Ǵ�����ʹ��ս������������Ϸ���������ţ������
���Ѽ��������ں�����һ����Ц�����һ������ֺ�����
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"out" : __DIR__"ship",
	]));
	set("objects", ([
		"/d/huanghe/npc/peng" : random(2),
		"/d/huanghe/npc/sha" : random(2),
		"/d/huanghe/npc/liang" : random(2),
		"/d/huanghe/npc/hou" : random(2),
		"/d/huanghe/npc/ma" : random(2),
		"/d/huanghe/npc/qian" : random(2),
		"/d/huanghe/npc/shen" : random(2),
		"/d/huanghe/npc/wu" : random(2),
		"/kungfu/class/xueshan/lingzhi" : random(2),
		"/kungfu/class/btshan/ouyangfeng" : random(2),
		"/kungfu/class/btshan/ouyangke" : random(2),
		__DIR__"npc/duantiande" : random(2),
		__DIR__"npc/wanyankang" : random(2),
		__DIR__"npc/wanyanhonglie" : random(2),
		__DIR__"npc/jinbing" : random(4),
	]));
	setup();
	replace_program(ROOM);
}
