// Room: /d/shaolin/cjlou2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
        set("short", "藏经阁");
        set("long", @LONG
千余年来少林寺执中原武林之牛耳，自达摩老祖以下，历代
人材辈出。其中有不少高僧遗著留存，汇集至今，终成名震天下
的少林七十二绝艺。少林精华，尽集于此。三楼四面开窗，确保
通风。中间排列着五排大书架。慕容复就是藏身与此，偷学少林
绝学。
LONG );
        set("exits", ([
                "south" : __DIR__"cjlou",
        ]));
        set("objects",([
//                CLASS_D("shaolin") + "/hui-zhen" : 1,
                  "/d/murong/npc/murong-bo": 1,
                  "/d/murong/npc/saodiseng": 1,
//                "/clone/book/yijinjing" : 1,
        ]));
//      set("no_clean_up", 0);
        setup();
}

