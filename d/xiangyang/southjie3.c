// Room: /d/xiangyang/southjie3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������������ϴ�ֵ���ͷ�����������ȸ���ţ����߷�
�����֡�������Ϊ�������ؾ��������������ı����̡�ʮ����
���������ɹž����ַ������������Ĵ���������һֱ�����ͣ��
�����������ǵ��ϱ�Ӫ���������������洫���ı�ʿ�ǵĲ���
����
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"tiejiangpu",
		"west"  : __DIR__"bingying3",
		"south" : __DIR__"southgate1",
		"north" : __DIR__"southjie2",
	]));
	setup();
	replace_program(ROOM);
}
