/*  <SecCrypt CPL V3R05>  */
 
//  by  snowcat  on  7/5/1997  
inherit  NPC;

int  random2  (int  i)
{
    return  (random(i)+uptime())  %  i;
}

void  create()
{
    set_name("����",  ({  "sai  gui",  "gui"  })  );
    set("race",  "Ұ��");
    set("gender",  "����");
    set("age",  2);
    set("long",  "һֻ�����ڵ����ꡣ\n");
    set("attitude",  "friendly");
    set("str",  20+random2(2));
    set("spi",  20+random2(2));
    set("cor",  20+random2(2));
    set("con",  20);
    set("cor",  20);
    set("cps",  20);
    set("dex",  20);
    set("per",  20);
    set("limbs",  ({  "ͷ��",  "צ��",  "β��"  })  );
    set("verbs",  ({  "bite"})  );

    setup();
}

