inherit ROOM;

void create()
{
        set("short", "�껨Ժ");
        set("long",@LONG
�ഫ������潵�������´���ʱ����������껨ʯ��������ʯ��
Ժ�����ɴ˼���Ժ��Ժ�г���̴�����磬�����Ŀ�������
LONG );
        set("exits", ([
                "west" : __DIR__"wuwujing",
		"south" : __DIR__"doumugong",
	]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
