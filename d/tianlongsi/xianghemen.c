inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",@LONG
����ͨ�������º��µ��Ż������ͷ�������ϣ�ֻ��ͭ�ż����ѱ���
̤�����������������֮ʢ�ˡ�̧ͷ���Ͽ����������ɽ�������졣
LONG );
        set("outdoors","tianlongsi");
        set("exits", ([
            "south": __DIR__"wulege",
            "north": __DIR__"wujingge",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
