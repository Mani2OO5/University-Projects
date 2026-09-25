Donation = {
    ('Alexander','boubou'   ) : (200_000_000 , 100_000   ),
    ('Barbara'  , 'kimkim'  ) : (5_000_000   , 4_000_000 ),
    ('Albert'   , 'jojo'    ) : (1_000_000   , 500_000   ),
    ('Daniel'   , 'wiliwili') : (50_000_000  , 10_000_000),
    ('Eliot'    , 'minmin'  ) : (15_000_000  , 5_000_000 )
}

def Donate_cal(Dictionary):

    Person  = ''
    Add     = 0
    Avg     = 0
    MAXimum = 0
    minumum = 0
    
    #Unpacking Values:
    Incomes = []
    Donates = []

    Incomes = [Donate[0] for Donate in Dictionary.values()]
    Donates = [Donate[1] for Donate in Dictionary.values()]

    #Add:
    for Donate in Donates:
       Add += Donate
    
    #Avg:
    Avg = Add // len(Dictionary)

    #MAXimum & minimum:

    Donation_ratio = map(lambda Donate, Income : Donate/ Income , Dictionary.values())
    
    MAXimum = Donation_ratio[0]
    minimum = Donation_ratio[0]

    for Donate in Donation_ratio:
        if Donate > MAXimum:
            MAXimum = Donate
        if Donate < minimum:
            minimum = Donate

    return Add , Avg , MAXimum , minimum, Person

    

print(

f"""


 

"""
)

print(Donate_cal(Donation))

