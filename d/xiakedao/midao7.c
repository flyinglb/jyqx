// midao7.c �ܵ�

inherit ROOM;

void create()
{
        set("short", "����ͨ��");
        set("long", @LONG
����һ��ʯ�ң����Ϻͽ��䶼�ǻҳ�����źþ�û�������ˡ���
ʯ��֮�䣬���ż���С��(cao) ������ϸһ����ԭ�������Ƕϳ�ʴ��
���Ĳݡ�
LONG );
       set("exits", ([
               "east"    : __DIR__"midao6",
               "out"     : __DIR__"dating",
               "northup" : __DIR__"midao8",
       ]));
       set("objects", ([
               __DIR__"obj/cao" : 1,
       ]));
       setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out")
            tell_object(me,"���߳�������ͨ�������صس����ڴ���֮�С�\n");
        return ::valid_leave(me,dir);
}
