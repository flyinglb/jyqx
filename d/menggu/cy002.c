inherit ROOM;

void create()
{
        int kind=random(6);

        set("short", "大草原");

        switch(kind)
        {
        case 0:
                set("long",@LONG
蓝蓝的天上飘着白云，远远的原野缀着牛羊，缓缓的丘陵覆满碧草，悠悠
的牧笛充满忧伤。这里就是阴山以北辽阔的草原。
long);
        break;
        
        case 1:
                set("long",@LONG
蓝蓝的天上飘着白云，远远的原野缀着牛羊，缓缓的丘陵覆满碧草，悠悠
的牧笛充满忧伤。这里就是雁门以北广阔的草原。
LONG);
        break;

        case 2:
                set("long",@LONG
蓝蓝的天上飘着白云，远远的原野缀着牛羊，缓缓的丘陵覆满碧草，悠悠
的牧笛充满忧伤。这里就是河套以北富饶的草原。
LONG);
        break;

        case 3:
                set("long",@LONG
蓝蓝的天上飘着白云，远远的原野缀着牛羊，缓缓的丘陵覆满碧草，悠悠
的牧笛充满忧伤。这里就是成吉思汗的发祥故乡。
LONG);
        break;

        case 4:
                set("long",@LONG
一望无垠的草原上远远传来凌乱的马蹄声，你甚至无法分清这声音来自何
方，过了许久你才看到一队蒙古骑兵跨弓携箭匆匆而过，一片轻微的尘烟过去
便是远去的马蹄声。
LONG);
        break;

        default:
                set("long",@LONG
青青的山坡上响起惊天动地的声音，原来是无数的野马狂奔而来，几个剽
悍的牧民拿着绳套骑着骏马在后面追赶，口中大声地呼啸着什么，不时看到有
被套倒的野马。不过盏茶工夫，铺天盖地的马群已然风弛而去。
long);
        break;
        }

        set("exits",([
                "east"          :__DIR__"",
                "southeast"     :__DIR__"cy001",
                "south"         :__DIR__"",
                "southwest"     :__DIR__"",
                "west"          :__DIR__"",
                "northwest"     :__DIR__"cy003",
                "north"         :__DIR__"",
                "northeast"     :__DIR__"",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "menggu");
//      set("sleeproom", 1);
        setup();
        replace_program(ROOM);
}
