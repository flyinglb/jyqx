// room: dong-2.c
// zqb


inherit ROOM;
#include <ansi.h>
string look_bei();
void create()
{
        set("short", HIR"ÌìÈ»¶´Ñ¨"NOR);
        set("long", @LONG
    ÕâÊ¯¶´ÏµÌìÈ»Éú³É£¬½ÏÖ®ÍâÃæÈË¹¤¿ªÔäµÄÊ¯ÊÒ´óÁËÊ®À´±¶¡£·ÅÑÛÍû
È¥£¬¶´ÄÚ¹²ÓĞÊ®Óà¾ßº¡¹Ç£¬»ò×ö»òÎÔ£¬ÉñÌ¬¸÷ÓĞ²»Í¬£¬ÓĞµÄº¡¹ÇÉ¢¿ªÔÚµØ£¬
ÓĞµÄÈ´ÈÔ¾ßÍêºÃÈËĞÎ£¬¸üÓĞĞ©¹ÇÌ³ÁéÎ»Ö®Êô¡£Ã¿¾ßº¡¹ÇÖ®ÅÔ¶¼·Å×Å±øÈĞ£¬°µ
Æ÷£¬ÓÃ¾ß£¬Õä±¦µÈÎï¡£¶´¿Ú´¦Á¢×ÅÒ»×ùÊ¯±®(bei)¡£
LONG
        );
        set("exits", ([
            "out" : __DIR__"dong-3",
        ]));
        set("item_desc",([
        "bei"         :       (: look_bei :),
    ]));

        set("objects", ([
           
        __DIR__"obj/haigu2" : 1,  
        __DIR__"obj/ycj" : 1,      
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}
string look_bei()
{
        return
        "\n"
"    Ì   ÉÃ¶¯ÊÒÄÚÎïÆ·Õß\n"    
        "\n"
RED"        ËÀÉËÄª¹Ö£¡    \n"NOR
        "\n";
}

