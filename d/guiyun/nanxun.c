// Room: /guiyun/nanxun.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ݸ������ķ���ʢ��������ʿ��������ʱ���й��ַ�Ϊƽ��ȥ
����������Լ��Ԫ���黭���鼫Ʒ�������׶��Ǻ������ϡ���������
��������������֮�ʣ�����֮ī������ֽ֮�������Ϫ֮�⣬�ķ���
�������³�������������Ǻ��ݸ���һ����ȴ��Ѱ�����ػ�����
�ϸ������࣬�����ĸ��Ҵ���֮����һ����ׯ��
LONG );
        set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"yixing",
	]));
	setup();
	replace_program(ROOM);
}
