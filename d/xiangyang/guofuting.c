// Room: /d/xiangyang/guofuting.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ǹ����Ŀ��������䲻��ȴ���õ�ͦ���¡�������
�����ķ������������÷���������ֻ��ܣ��������ҵ��Ǵ���
�ﶬ���������е���һ�Ű����������϶˷���һ�ײ�ߣ�����
�ڷ�������̴���Σ��Եü�Ϊ���ӡ����Ǹ��ڷ���һ��ĵ������
�ƺ����������һ˿ů�⡣������ǽ�����蹩�����ɵĻ���
������һ����������顰���Һ�ɽ����
LONG );
	set("exits", ([
		"south" : __DIR__"guofuyuan",
		"north" : __DIR__"guofuhuayuan",
	]));
	set("objects", ([
		__DIR__"npc/guo" : 1,
	]));
	setup();
	replace_program(ROOM);
}

