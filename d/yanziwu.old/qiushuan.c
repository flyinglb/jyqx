
//ROOM: /d/yanziwu/qiushuan.c

inherit ROOM;

void create()
{
        set("short", "��ˬի");
        set("long",@LONG
��ᣵʹ����豸���أ��ٴ������϶������ᣬһ��Ͱë����ʾ����
��ѧʶԨ����һֻ���λ�ƿ���ż����绨�������������µ���Ϣ��
LONG );
        set("exits", ([
            "east" : __DIR__"canheju",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
