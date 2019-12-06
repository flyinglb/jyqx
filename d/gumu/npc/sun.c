// sun.c ������

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({"sun popo", "sun"}));
        set("gender", "Ů��");
        set("age", 55);
        set("long",
                "����һλ����������ţ���������΢΢һЦ��\n"
        );
        set("attitude", "friendly");

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 40);

        set("combat_exp", 150000);
        set("score", 0);

        set_skill("force", 80);
        set_skill("yunv-xinfa", 60);    //��Ů�ķ�
        set_skill("sword", 90);
        set_skill("yunv-jian", 80);     //��Ů��
        set_skill("dodge", 70);
        set_skill("yunv-shenfa", 70);   //��Ů��
        set_skill("parry", 60);
        set_skill("unarmed",80);
        set_skill("meinv-quan", 60);    //��Ůȭ��
        set_skill("literate",40);

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        set("inquiry", ([
                "С��Ů" :  "����������һ�ִ���ģ�����Сû�˸�ĸ�������ֶ�����ס�����Ĺ���..\n",
        ]) );

        set("env/wimpy", 50);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("clone/misc/cloth")->wear();

}

