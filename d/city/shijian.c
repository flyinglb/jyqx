inherit ROOM;

void create()
{
        set("short", "�Խ���");
        set("long", @LONG
����������֮�����������һ����ɱ֮��ʹ�����һ����������
���󲢲����Ž��֣��ƺ����ڴ�ʲô��һ�Եļ����ϰ��ż�����ϰ��
���񽣡���������һ���Ҷ�(sign)��
LONG
        );
        set("no_die", 1);
        set("no_get", 1);
        set("exits", ([
                 "south": __DIR__"wumiao",
]));
set("item_desc", ([
                "sign": @TEXT
   ��̨�۽�
���¹���
TEXT
        ]) );

        setup();
        replace_program(ROOM);
}
