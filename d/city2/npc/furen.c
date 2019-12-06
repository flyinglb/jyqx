// furen.c
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("ׯ����", ({ "san furen", "san","furen"}));
        set("title", "ׯ����������" );
        set("nickname", HIW "δ����" NOR);
        set("long",  "\nֻ����ԼĪ��ʮ�������,ȫ������,��ʩ֬��,��ɫ�԰�.\n");
        set("gender", "Ů��");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 30);
        
        set("max_qi", 1000);
        set("max_jing", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("combat_exp", 100000);
        set("score", 50000);

        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("unarmed", 90);
        set_skill("sword", 90);
        set_skill("taiji-jian", 80);
        set_skill("tiyunzong",90);
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "tiaji-jian");
        map_skill("sword", "tiaji-jian");

        set_temp("apply/attack", 35);
        set_temp("apply/attack", 35);
        set_temp("apply/damage", 35);
        set("inquiry", ([
                "����" : "�������ҼҵĴ���ˡ�",
                "��֮��" :"��һ��Ҫ���������������",
                "����" :  "��������ɲ�һ��,�������ҵĺ�Ѿ��˫����",
                "˫��" :  "��СѾͷ�����Ҷ���,����Ҳ���׵���",
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob; 
        ob = this_player();

        if( interactive(ob) && !is_fighting() ) 
        say( "ׯ����˵�����ܾ�û��������,��λ" + RANK_D->query_respect(ob)
                                + "����֪�����๫��������?\n");
}

int accept_object(object me, object ob)
{
        int i;
        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0; 
        if ( !present(ob, me) ) return notify_fail("��û�����������");
        if ( (string)ob->query("id") == "wu zhi rong") 
        {
        //i=(int)this_player()->query("weiwang");
        i=(int)me->query("weiwang");
        if(i>=50&&i<70)
        {
        i=i+10;
        //this_player()->set("weiwang",i);
        me->set("weiwang",i);
        message_vision(HIC "\n$N�Ľ�����������ˣ�\n" NOR,me);
        //command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(i));
        command("tell "+me->query("id")+" �����ڵĽ��������� " +(string)(i));
        write(HIC "\nׯ���˴�ϲ��������,����!�벻����Ҳ�н���!!!\n");
        ob->die();
        }
//         if(this_player()->query("weiwang")>=70)
         if(me->query("weiwang")>=70)
         {
         write(HIC "\nׯ����˵������λ" + RANK_D->query_respect(me)+",��˴�����,���ʵ��֪����Ϊ��.\n");
         write(HIC "�����Ͷ���һ������,������ȴ����.\n");
         }
        }               
        if ( (string)ob->query("name") == "��ʷ����") 
        {
         write(HIC "\nׯ����˵������λ" + RANK_D->query_respect(me)+",��л��.\n");
         write(HIC "��,��Ҫ�ܰ����ҵ���֮���⹷���ͺ���.\n");
        }               
        if ( (string)ob->query("name") == "ׯ�ʳ�") 
        {
         write(HIC "\nׯ����˵������λ" + RANK_D->query_respect(me)+",��л��.\n");
         write(HIC "��,��Ҫ�ܰ����ҵ���֮���⹷���ͺ���.\n");
        }               
 return 1;
}
