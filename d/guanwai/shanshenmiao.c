// /guanwai/shanshenmiao.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����һ����ľ���ʯͷ�ݳɵ�С����ǰ����ɢ����һЩȻ���Ļҽ���
���﹩����ɽ��ү�ϰ�ͷ����λ(lingwei)����˵�������вɲ��˵���ʦү��
����ÿ����ɽ�ڲεĲοͶ�Ҫ��������ݣ�ϣ���ܵõ������˼ҵı��ӡ�
LONG );
	set("item_desc", ([
		"lingwei"  : 
"
**************
*            *
*     ɽ     *
*     ��     *
*     ү     *
*     ��     *
*     ��     *
*     ͷ     *
*            *
*     ��     *
*     ��     *
*            *
*     ֮     *
*     λ     *
*            *
**************
"
	]));
	set("exits", ([
		"out"  : __DIR__"huandi2",
	]));
	set("objects", ([
		__DIR__"npc/yanji" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

