// Room: /city/mingren.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
string look_shu();

void create()
{
	set("short", "������");
	set("long", @LONG
�������������һ�ٵ������á������﹩����д�����Ҳ��ħͷ��
Ҳ�в��Ǵ�������ħͷ����ҡ���������һλ�������ھ�һʱ������
һ�����������Ķ��ǵĹ��£�ÿһ�����¶�������Զ��Ӱ����һ����
����������ҡ�
    ��Ȼ���Ƕ�����������������������ķ��꣬���������Ҳ��
���ڽ��������ˡ����Ƕ��Ѿ��˳������������ǵ���Ӱħ�ٺܳ�ʱ��
�Ժ�����һ����˵��
LONG );

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"wumiao2",
	]));
	set("objects", ([
		__DIR__"player/abab": 1,
//		__DIR__"player/cnba": 1,
		__DIR__"player/fandog": 1,
		__DIR__"player/qinqin": 1,
		__DIR__"player/wuqing": 1,
		__DIR__"player/wuxiangxinmo": 1,
		__DIR__"player/xem": 1,
	]));
	setup();
	replace_program(ROOM); 
}

