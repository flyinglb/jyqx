// xiuxishi.c
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
������÷ׯ�����������۵�ʱ����Ϣ�ĵط������ﾭ��������
�����׵�����������򵥵ķ��ż��ŵ��ӣ������ޱ���������ͷ����
��÷ׯ������Ȼ������ɨ�����������Ȼ���Ҳ������ܶ�÷ׯ����
һ�������ͷ��˯�����ǹ���ƣ�͵�Ե�ʡ� 
LONG
        );
        set("sleep_room", "yes");
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"zoulang2",
        ]));
        set("no_fight", "yes");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

