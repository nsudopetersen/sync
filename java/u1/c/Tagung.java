/* */

enum Akademische_Rolle { DOKTORAND, POSTDOC, PROFESSOR}

public class Adresse {
    private String strasse;
    private String stadt;
    private int plz;
}

public class Teilnehmer {
    private String name;
    private int id;
    private Akademische_Rolle rolle;
}

public class Abstract_Veranstaltung {
    private String titel;
    private short dauer_min;
    private Adresse ort;
}

public class Vortrag extends Abstract_Veranstaltung {
    private Teilnehmer sprecher;
    private String thema;
}
public class Breakoutsession extends Abstract_Veranstaltung {
    private Teilnehmer leiter;
    private short teilnehmer_max;
}

public class Tagung {
    private String name;
    private Adresse adresse;
    private Teilnehmer leiter;
    private Teilnehmer protokollant;
    private Vortrag vortrag;
    private Breakoutsession breakoutsession;
}
