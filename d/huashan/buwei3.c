// buwei3.c

inherit ROOM;

void create()
{
        set("short", "ƫ��");
	set("long", @LONG
ƫ���﹩���Ż�ɽ������ʦ����λ�������񰸵�ǽ���ǻ�ɽ�ɿ�ɽ��
ʦ����ʦ�Ļ��󡣻��������������ǳ�����������¯������������㣬
��������������ɢ����һ��̴��ζ������������ͨ�������������
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"buwei1",
	]));
        set("no_clean_up", 0);
        set("valid_startroom","1");

        setup();
        "/clone/board/huashan_b"->foo();
        replace_program(ROOM);
}
