// yufu.c
// Date: YZC 96/01/19

inherit NPC;

void create()
{
        set_name("Óæ·ò", ({ "yu fu" }) );
        set("gender", "ÄĞĞÔ" );
        set("age", 22);
        create_family("ÏÀ¿Íµº", 2, "µÜ×Ó");
        setup();
}
int accept_object(object me, object ob)
{
        object ling1;
        object ling2;


        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("id"));
        ling1->move(me);
        message_vision("Óæ·ò¸ø$NÒ»¿éÍ­ÖıÁîÅÆ¡£\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("id"));
        ling2->move(me);
        message_vision("Óæ·ò¸ø$NÒ»¿éÍ­ÖıÁîÅÆ¡£\n", me);

        return 1;
}
