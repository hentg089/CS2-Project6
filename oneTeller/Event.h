//Mark Hentges 5814124 Part 1:One Teller


#ifndef ONETELLER_EVENT_H
#define ONETELLER_EVENT_H

#include "EventType.h"
#include "Time.h"

class Event {
private:
    EventType type;
    Time time;
    Time duration;
    int customerNumber;
public:
    /** setter for type
     * @pre needs valid type
     * @post sets the type to the param
     * @param type set to type
     */
    void setType(EventType type);

    /** setter for time
     * @pre needs valid time
     * @post sets the time
     * @param time we use to set time
     */
    void setTime(Time time);

    /** setter for duration
     * @pre needs valid duration
     * @post needs to set duration
     * @param duration we se to duartion
     */
    void setDuration(Time duration);

    /**sets the customer number
     * @pre needs valid number
     * @post changes the customer number
     * @param customerNumber that will be set
     */
    void setCustomerNumber(int customerNumber);

    /**gets the time
     * @pre needs to be initialized
     * @post none
     * @return the time
     */
    Time getTime() const;

    /**gets type
     * @pre needs initialized type
     * @post none
     * @return the event type
     */
    EventType getType() const;

    /**gets duration
     * @pre needs initialized type
     * @post none
     * @return the duration
     */
    Time getDuration() const;

    /**gets number
     * @pre needs initialized type
     * @post none
     * @return the number
     */
    int getNumber() const;

    /**operator overlaod for <
     * @pre none
     * @post none
     * @param rhs of the <
     * @return lhs < rhs bool value
     */
    bool operator<(const Event& rhs) const;

    /**operator overlaod for >
     * @pre none
     * @post none
     * @param rhs of the >
     * @return lhs > rhs bool value
     */
    bool operator>(const Event& rhs) const;

    /**operator overlaod for <=
     * @pre none
     * @post none
     * @param rhs of the <=
     * @return lhs <= rhs bool value
     */
    bool operator<=(const Event& rhs) const;

    /**operator overlaod for >=
     * @pre none
     * @post none
     * @param rhs of the >=
     * @return lhs >= rhs bool value
     */
    bool operator>=(const Event& rhs) const;

    /**operator overlaod for ==
     * @pre none
     * @post none
     * @param rhs of the ==
     * @return lhs == rhs bool value
     */
    bool operator==(const Event& rhs) const;

    /**operator overlaod for !=
     * @pre none
     * @post none
     * @param rhs of the !=
     * @return lhs != rhs bool value
     */
    bool operator!=(const Event& rhs) const;

};


#endif //ONETELLER_EVENT_H
