inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
这是庄主的书房，琳琅满目，全是诗书典籍，几上桌上摆着
许多铜器玉器，看来尽是古物，壁上挂着一幅水墨画，画的是个
中年书生在月明之夜中庭伫立。
LONG );
        set("no_sleep_room", "1");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"qianyuan",
        ]));
        setup();
}
