// /guanwai/xiaotianchi.c

inherit ROOM;

void create()
{
	set("short", "�ڷ��");
	set("long", @LONG
�����������е��ն�֮����Χ��Ϊï�ܵ����֣�������⡣���д���Ұ
�޼���֮����˻���Ĵ��в�֪���Ĳ��Ժ�Ұ��������һ��Ҳ���ҳ�������
ľ�İ����䣬�ƺ�����ɱ�����㵽�˴˴����ĵ����ѣ�ֻ�����뿪��
LONG );
	set("exits", ([
		"east"     : __DIR__"xiaotianchi",
		"westdown" : __DIR__"milin3",
	]));
	set("objects", ([
		__DIR__"npc/bear" : 1,
	]));
	setup();
	replace_program(ROOM);
}
