// Room: /lingzhou/daodian.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����������ز���Ӣ������С�������ı����̣��ϰٰѸ�
ʽ�����ġ�Ӣ������С����������İڷ��ڹ�̨�ϣ�˵��С��ȴ�ߴ�
���ƴ���ͬ�����г���һ�����Ҷ�ɵ���Ҳ�г������ߵİ�������
�������Ļ��ǳ����磬�����֣�����һ���б���ֽ��ذ�׹�̨��
���ǽ��Ҳ����Щ�������ֵ������ȵ���ԭ������
LONG );
	set("exits", ([
		"north"  : __DIR__"xidajie",
	]));
	set("objects", ([
		__DIR__"npc/daodianhuoji" :1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

