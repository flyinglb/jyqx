inherit NPC ;
void create()
{
          set_name("仆人", ({ "pu ren","ren"}));
          set("gender","男性");
          set("age",34);
         set("long","这个仆人可怜兮兮的，他是因为犯了错才被弄到这里来的\n");
          set("attitude", "friendly") ;
          set("combat_exp",1000);

      setup();
}
